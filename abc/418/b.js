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
    const S = input[0];
    const lenS = S.length;
    //console.log(lenS);
    let maxFillRate = 0;

    for(let i=0; i<lenS-2; i++){
        if(S[i] === 't'){
            for(let j=i+2; j<lenS; j++){
                if(S[j] === 't'){
                    //console.log(i, j);
                    let numT = 0;
                    for(let k=i+1; k<j; k++){
                        if(S[k] === 't'){
                            numT += 1;
                        }
                    }
                    const fillRate = numT/(j-i-1);
                    if(fillRate > maxFillRate){
                        maxFillRate = fillRate;
                    }
                }
            }
        }
    }
    console.log(maxFillRate);
});