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
    const x = Number(input[0]);
    const n = Number(input[1]);
    const W = input[2].split(' ').map(Number);
    const numQ = Number(input[3]);

    const boolW = new Array(n).fill(false);
    let sumWeight = x;
    //console.log(boolW);
    for(let i=4; i<4+numQ; i++){
        const q = Number(input[i]);
        if(boolW[q-1]){
            sumWeight -= W[q-1];
            boolW[q-1] = !boolW[q-1];
        }
        else{
            sumWeight += W[q-1];
            boolW[q-1] = !boolW[q-1];
        }
        console.log(sumWeight);
    }
});