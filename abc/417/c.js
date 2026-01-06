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
    const A = input[1].split(' ').map(Number);
    // j - i = A[i] + A[j], A[i] + i = j - A[j]
    const AiPlusI = new Array(200001).fill(0);
    const jMinusAj = new Array(200001).fill(0);
    for(let i=0; i<n; i++){
        if(A[i]+i+1 < 200000){
            //console.log(AiPlusI[A[i]+i+1]);
            //console.log(A[i]+i+1);
            AiPlusI[A[i]+i+1] += 1;
            //console.log(AiPlusI[A[i]+i+1]);
        }
        if(i+1-A[i] > 1){
            //console.log(jMinusAj[i+1-A[i]]);
            //console.log(i+1-A[i]);
            jMinusAj[i+1-A[i]] += 1;
            //console.log(jMinusAj[i+1-A[i]]);
        }
    }
    let result = 0;
    for(let j=2; j<200001; j++){
        result += AiPlusI[j] * jMinusAj[j];
    }
    console.log(result);
});