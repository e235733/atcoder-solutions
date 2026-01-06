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
    const n = Number(input[0]);
    const S = input[1];

    //[A,B,A,B, ...]のパターンを試す
    let sumPattern1 = 0;
    let nextIddialAIndex = 0;
    for(let i = 0; i<n*2; i++){
        //S[i]がAなら、理想のインデックスと比較してその絶対値をsumし、次の理想のインデックスに+2
        if(S[i] === 'A'){
            //console.log(i, S[i]);
            sumPattern1 += Math.abs(i - nextIddialAIndex);
            nextIddialAIndex += 2;
        }
    }
    //console.log(sumPattern1);

    //[B,A,B,A, ...]のパターンを試す
    let sumPattern2 = 0;
    let nextIddialBIndex = 0;
    for(let j=0; j<n*2; j++){
        if(S[j] === 'B'){
            sumPattern2 += Math.abs(j - nextIddialBIndex);
            nextIddialBIndex += 2;
        }
    }
    console.log(Math.min(sumPattern1,sumPattern2));
});