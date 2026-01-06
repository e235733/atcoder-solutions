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
    const numQ = Number(input[0]);

    //何番目まで同じ値なのかを示すmC、その値を示すmX
    // 削除の代わりにheadの位置を移動していく
    let head = 1;
    const mC = [0];
    const mX = [0];
    let mHead = 1;
    for(let i=1; i<=numQ; i++){
        const q = input[i].split(' ').map(Number);
        if(q[0] === 1){
            const [c, x] = [q[1], q[2]];
            //console.log(c, x);
            mC.push(c);
            mX.push(x);
            //console.log(mC);
        }
        else{
            const k = q[1];
            let leftK = k;
            const mLength = mC.length;
            let sum = 0;
            for(let j=mHead; j<mLength; j++){
                //console.log(leftK, sum, mC[j], mX[j]);
                //console.log(c);
                if(mC[j] < leftK){
                    sum += mC[j]*mX[j];
                    leftK -= mC[j];
                }
                else{
                    sum += leftK*mX[j];
                    mC[j] -= leftK;
                    mHead = j;
                    console.log(sum);
                    break;
                }
            }
        }
    }
});