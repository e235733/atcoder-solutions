'use strict';

const fs = require('fs');
const readline = require('readline');

const isAtCoder = process.platform === 'linux';

const inputStream = isAtCoder
    ? process.stdin
    : fs.createReadStream('./input.txt');

const rl = readline.createInterface({
    input: inputStream,
});

const input = [];
rl.on('line', (line) => {
    input.push(line);
});

rl.on('close', () => {
    const numTestCase = Number(input[0]);
    let inputIndex = 1; // input配列の何行目を読んでいるかを追跡

    testCaseLoop: // 各テストケースを中断して次に進むためのラベル
    for(let i = 0; i < numTestCase; i++){
        // 現在のテストケースの入力を読み込む
        const numDomino = Number(input[inputIndex]);
        const Dominos = input[inputIndex + 1].split(' ').map(Number);
        
        // 次のテストケースのためにインデックスを2つ進める
        inputIndex += 2; 

        const S1 = Dominos[0];
        const SN = Dominos[numDomino - 1];

        // 1. ドミノ1からNに直接届くか
        if(SN <= S1 * 2){
            console.log(2);
            continue testCaseLoop;
        }

        // 2. 中間のドミノをソート
        const sortedMiddle = Dominos.slice(1, numDomino - 1).sort((a,b) => a-b);
        
        let count = 2; // (ドミノ1とN)
        let currentMaxSize = S1; // 現在の連鎖の最後のドミノのサイズ
        let middleIndex = 0; // ソート済み中間ドミノのどこまで見たか

        while(true) {
            let nextMaxSize = -1;
            let range = currentMaxSize * 2;
            
            // 3. 届く範囲で、最強のドミノ(nextMaxSize)を探す
            // middleIndexから開始することで、使用済みのドミノを再検索しない
            while(middleIndex < sortedMiddle.length && sortedMiddle[middleIndex] <= range) {
                // 届くドミノが見つかるたび、最強のドミノを更新
                nextMaxSize = sortedMiddle[middleIndex];
                middleIndex++;
            }

            // 4. 届くドミノが1つも見つからなかった場合
            if(nextMaxSize === -1) {
                // 連鎖が途切れた
                console.log(-1);
                continue testCaseLoop;
            }

            // 5. 届くドミノが見つかった場合
            count++; // ドミノを1つ追加
            currentMaxSize = nextMaxSize; // 最強のドミノにジャンプ

            // 6. 新しいドミノからNに届くかチェック
            if(SN <= currentMaxSize * 2) {
                console.log(count);
                continue testCaseLoop;
            }
            
            // 届かなければ while(true) ループが継続
        }
    }
});