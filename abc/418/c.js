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
    const [n, q] = input[0].split(' ').map(Number);
    const A = input[1].split(' ').map(Number);

    let maxA = 0;
    //ティーバッグがi個あるフレーバーの数。numBag[バッグ数] = フレーバー数
    const numBag = new Array(1000001).fill(0);
    for(let i=0; i<n; i++){
        numBag[A[i]] += 1;
        if(maxA < A[i]){
            maxA = A[i];
        }
    }
    //console.log(numBag);

    let nextNum = n;

    //全てのフレーバーをb-1個まであるだけ集めた合計
    const totalToB = new Array(maxA+1).fill(0);
    //console.log(totalToB);
    for(let j=1; j<maxA+1; j++){
        totalToB[j] = totalToB[j-1] + nextNum;
        nextNum -= numBag[j];
    }
    //console.log(totalToB);

    for(let k=2; k<q+2; k++){
        const b = Number(input[k]);
        if(b >= maxA+1){
            console.log(-1)
        }
        else{
            const result = totalToB[b-1] + 1;
            console.log(result);
        }
    }
});