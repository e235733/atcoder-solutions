'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim();

const sides = input.split(' ').map(Number);
if(sides[0] != sides[1] && sides[0] != sides[2] && sides[1] != sides[2]){
    console.log('No');
}
else{
    console.log('Yes');
}