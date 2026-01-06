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
    const [x, y] = input[0].split(' ').map(Number);
    let aIndexMinus2 = x;
    let aIndexMinus1 = y;
    for(let i=3; i<=10; i++){
        const nX = aIndexMinus2 + aIndexMinus1;
        const sX = String(nX);
        const sizeSX = sX.length;
        const listRevSX = [];
        for(let j=0; j<sizeSX; j++){
            listRevSX.push(sX[sizeSX-j-1]);
        }
        const revSX = listRevSX.join('');
        aIndexMinus2 = aIndexMinus1;
        aIndexMinus1 = Number(revSX);
    }
    console.log(aIndexMinus1);
});