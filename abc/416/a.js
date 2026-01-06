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
    const [n, l, r] = input[0].split(' ').map(Number);
    const S = input[1];

    const partS = S.slice(l-1, r);
    //console.log(partS);

    if(partS.includes('x')){
        console.log('No');
    }
    else{
        console.log('Yes');
    }
});