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

    const conbos = [];
    let numCombo = 0;
    for(let i=1; i<=n; i++){
        for(let j=1; j<=n; j++){
            if(i !== j){
                const conbo = input[i] + input[j];
                if(!conbos.includes(conbo)){
                    conbos.push(conbo);
                    numCombo += 1;
                }
            }
        }
    }
    //console.log(conbos);
    console.log(numCombo);
});