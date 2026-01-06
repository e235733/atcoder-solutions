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
    const [x, y] = input[n+1].split(' ');

    if(input[Number(x)] === y){
        console.log('Yes');
    }
    else{
        console.log('No');
    }
});