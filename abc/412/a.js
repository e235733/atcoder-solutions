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
    let sumAchieve = 0;
    for(let i=0; i<n; i++){
        const [a, b] = input[i+1].split(' ').map(Number);
        if(a<b){
            sumAchieve += 1;
        }
    }
    console.log(sumAchieve);
});