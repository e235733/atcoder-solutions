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
    const [n, k, x] = input[0].split(' ').map(Number);

    // 入力されたSnをソート
    const S = [];
    for(let i=1; i<n+1; i++){
        S.push(input[i]);
    }
    const sortedS = S.sort();

    // xを0-indexedにする
    let xLeft = x-1;
    const nStringX = []; // N進数に変換したときの各桁の数字を格納
    
    // xLeft を K桁のN進数に変換（上の桁から決定）し、配列に格納
    for(let j=k-1; j>=0; j--){
        const nPowJ = n**j;
        const index = Math.floor(xLeft / nPowJ);
        nStringX.push(index);
        xLeft = xLeft % nPowJ;
    }

    // nStringXのindexをsortedSに対応させて結果を出力する
    const resultS = [];
    for(const l of nStringX){
        resultS.push(sortedS[l]);
    }
    console.log(resultS.join(''));
});