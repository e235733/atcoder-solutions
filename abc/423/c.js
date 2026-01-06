'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const [n, r] = input[0].split(' ').map(Number);
const L = input[1].split(' ').map(Number);


let openLeftmost = n;//最も左の開いたドア
let openRightmost = -1;//最も右の開いたドア

for(let i=0; i<n; i++){
    if(L[i] === 0){
        if(openLeftmost === n){
            openLeftmost = i;
        }
        openRightmost = i
    }
}
//開いたドアが存在しない場合
if(openLeftmost === n){
    console.log(0)
}
//開いたドアが高橋に対してどう存在するかによって場合分け
else{
    let operateLeftmost;
    let operateRightmost;
    //左にのみ存在する場合
    if(openLeftmost < r && openRightmost < r){
        //操作する最も左のドア
        operateLeftmost = openLeftmost;
        operateRightmost = r-1;
    }
    //右にのみ存在する場合
    else if(openLeftmost >= r && openRightmost >= r){
        operateLeftmost = r;
        operateRightmost = openRightmost;
    }
    //左右に存在する場合
    else{
        operateLeftmost = openLeftmost;
        operateRightmost = openRightmost;
    }
    let sumOperate = 0;
    for(let i=operateLeftmost; i<=openRightmost; i++){
        if(L[i] === 0){
            sumOperate += 1;
        }
        else{
            sumOperate += 2;
        }
    }
    console.log(sumOperate);
}