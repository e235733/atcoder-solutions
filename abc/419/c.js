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
    let top = 1000000001;
    let bottom = 0;
    let mostLeft = 1000000001;
    let mostRight = 0;
    for(let i=1; i<n+1; i++){
        const p = input[i].split(' ').map(Number);
        if(p[0] < top){
            top = p[0];
        }
        if(p[0] > bottom){
            bottom = p[0];
        }
        if(p[1] < mostLeft){
            mostLeft = p[1];
        }
        if(p[1] > mostRight){
            mostRight = p[1];
        }
    }
    const h = bottom - top;
    const w = mostRight - mostLeft;
    console.log(Math.ceil(Math.max(h, w) / 2));
});