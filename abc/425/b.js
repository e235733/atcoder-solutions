'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').split('\n');

const n = Number(input[0]);
const numbers = input[1].split(' ').map(Number);

const numInA = [];
let numMinus1 = 0;
for(let i=0; i<n; i++){
    const input_num = numbers[i];
    //console.log(input_num);
    if(input_num === -1){
        numMinus1 += 1;
    }
    else if(!numInA.includes(input_num)){
        numInA.push(input_num);
    }
    else{
        console.log('No');
        process.exit(0);
    }
}
//console.log(numMinus1);
//console.log(numInA);
console.log('Yes');
const output = [];
let m = 1;
for(let i=0; i<n; i++){
    const ni = numbers[i];
    if(ni == -1){
        while(numInA.includes(m)){
            m += 1;
        }
        output.push(m);
        m += 1;
    }
    else{
        output.push(ni);
    }
    //console.log(ni)
    //console.log(output)
}
console.log(output.join(' '));