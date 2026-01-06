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
    const [n, m] = input[0].split(' ').map(Number);
    const A = input[1].split(' ').map(Number);
    const B = input[2].split(' ').map(Number);

    for(let i=0; i<m; i++){
        const indexAI = A.indexOf(B[i]);
        if(indexAI !== -1){
            A.splice(indexAI, 1);
        }
    }
    console.log(A.join(' '));
});