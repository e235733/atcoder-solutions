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
    const [n, m, k] = input[0].split(' ').map(Number);
    const H = input[1].split(' ').map(Number);
    const B = input[2].split(' ').map(Number);

    const sortedH = H.sort((a, b) => a - b);
    const sortedB = B.sort((a, b) => a - b);

    for(let i=0; i<k; i++){
        const h = sortedH[i];
        const b = sortedB[m-k+i];
        //console.log(h, b);
        if(h > b){
            console.log('No');
            return;
        }
    }
    console.log('Yes');
});