function solution(n)
{
    var answer = 0;

    
    var share = n;
    var mod = 0;
    while(share > 0) {
        answer += share % 10;
        share = Math.floor(share / 10);
    }

    return answer;
}