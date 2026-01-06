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
    const num_q = Number(input[0]);
    let balls = [];

    for(let i=1; i<num_q+1; i++){
        const q = input[i].split(' ').map(Number);
        //console.log(q);
        if(q[0] === 1){
            balls.push(Number(q[1]));
            //console.log(balls);
        }
        else{
            const min_num = Math.min(...balls);
            console.log(min_num);
            const index = balls.indexOf(min_num);
            //console.log(balls);
            //console.log(index);
            balls.splice(index, 1);
            //console.log(balls);
        }
    }
});