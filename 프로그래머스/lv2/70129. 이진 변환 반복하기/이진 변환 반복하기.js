function toBinary(num) {
    var res = "";
    var temp = Math.floor(num / 2);
    var mod  = num % 2;
    while( temp >0) {
        res = String(mod) + res;
        
        num = temp;
        temp = Math.floor(num / 2)
        mod = num % 2;
    }
    res = String(mod) + res;
    
    return res;
}

function solution(s) {
    var answer = [];
    
    var times = 0;
    var deletedZeros = 0;
    
    while(1) {
        if(s === "1") break;
        times++;
        var zeros = 0;
        for(var i=0;i<s.length;i++) {
            if(s.at(i) === "0") {
                zeros++;
            }
        }
        var ones = s.length - zeros;
        deletedZeros += zeros;
        s = toBinary(ones);
    }
    
    
    answer.push(times);
    answer.push(deletedZeros);
    
    return answer;
}