function solution(A,B){
    var answer = 0;

    A.sort((a, b) => a-b);
    B.sort((a, b) => a-b);
    
    
    var i;
    const len = A.length -1;
    for(i=0;i<=len;i++) {
            answer += A[i] * B[len-i];
    }
    

    return answer;
}