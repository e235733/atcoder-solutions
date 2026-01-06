'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

// --- 1. 入力受け取り ---
const [n, q] = input[0].split(' ').map(Number);
const A = input[1].split(' ').map(Number);

// --- 2. 事前計算（ここが重要！） ---

// 配列を2つ連結して、回転を簡単に扱えるようにする
const doubledA = A.concat(A);

// 連結した配列の累積和を計算しておく
// これで区間和が O(1) で求まる
const prefixSum = new Array(2 * n + 1).fill(0);
for (let i = 0; i < 2 * n; i++) {
  prefixSum[i + 1] = prefixSum[i] + doubledA[i];
}

// --- 3. クエリ処理 ---

// 配列の先頭が何個ずれたかを管理する
let shiftAmount = 0;

// クエリは入力の3行目（インデックス2）から始まる
for (let i = 2; i < q + 2; i++) {
  const query = input[i].split(' ').map(Number);
  const queryType = query[0];

  if (queryType === 1) {
    // タイプ1: 先頭のずらし量を更新するだけ (O(1))
    const c = query[1];
    shiftAmount = (shiftAmount + c) % n;
  } else {
    // タイプ2: 累積和を使って合計を計算する (O(1))
    const l = query[1];
    const r = query[2];

    // 連結配列上での開始位置と終了位置を計算
    const start_idx = shiftAmount + l - 1;
    const end_idx = shiftAmount + r - 1;

    // 累積和を使って一瞬で合計を求める
    const sum = prefixSum[end_idx + 1] - prefixSum[start_idx];
    console.log(sum);
  }
}