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
    //console.log(S);
    const sortedS = S.sort();
    //console.log(sortedS);

    // nXtringX[i]にn進数化したx-1を保存する
    let xLeft = x-1;
    const nStringX = [];
    for(let j=k-1; j>=0; j--){
        // xLeftがn^k何個分か、引けるだけ引いて下の桁に渡す
        nStringX.push(Math.floor((xLeft) / n**j));
        xLeft %= n**j;
    }
    //console.log(nStringX);

    // nStringX[i]をsortedSのindexに対応させて結果を出力する
    const resultS = [];
    for(const l of nStringX){
        resultS.push(sortedS[l]);
    }
    console.log(resultS.join(''));
});