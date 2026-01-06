'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const n = Number(input[0]);

// learned[i]: スキルiが習得済みか
const learned = new Array(n + 1).fill(false);
// queue: 新たに習得したスキルを入れておく場所
const queue = [];
// unlocks[j]: スキルjを習得すると、習得可能になるスキルのリスト
const unlocks = Array.from({ length: n + 1 }, () => []);

// --- 1. 準備フェーズ ---
// 依存関係リストを作成し、最初に習得済みのスキルをキューに入れる
for (let i = 1; i <= n; i++) {
    const [a, b] = input[i].split(' ').map(Number);

    if (a === 0) { // (A,B)=(0,0)は最初から習得済み
        if (!learned[i]) {
            learned[i] = true;
            queue.push(i);
        }
    } else {
        // スキルiは、スキルaかbを習得すると習得可能になる
        // 逆引きリストを作成: スキルaを習得 -> スキルiがロック解除候補に
        unlocks[a].push(i);
        unlocks[b].push(i);
    }
}

// --- 2. 連鎖処理フェーズ (BFS) ---
// キューが空になるまで、連鎖的にスキルを習得していく
let head = 0; // shift()は遅いので、インデックスでキューの先頭を管理
while (head < queue.length) {
    const currentSkill = queue[head];
    head++;

    // currentSkillを習得したことで、新たに習得可能になるスキルをチェック
    for (const dependentSkill of unlocks[currentSkill]) {
        // そのスキルがまだ未習得なら、
        if (!learned[dependentSkill]) {
            // 習得済みにし、キューに追加して次の連鎖につなげる
            learned[dependentSkill] = true;
            queue.push(dependentSkill);
        }
    }
}

// --- 3. 結果出力 ---
// 最終的にキューに入ったスキルの総数が答え
console.log(queue.length);