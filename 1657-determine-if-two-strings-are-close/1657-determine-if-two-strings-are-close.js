/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    if(word1.length != word2.length){
        return false;
    }
    const freq1 = Array(26).fill(0);
    const freq2 = Array(26).fill(0);

    for(const ch of word1){
        freq1[ch.charCodeAt(0)-97]++;

    }
    for(const ch of word2){
        freq2[ch.charCodeAt(0)-97]++;
    }

    for(let i=0; i<26; i++){
        if((freq1[i]==0) !== (freq2[i]==0)){
            return false;
        }
    }

    freq1.sort((a,b)=>a-b);
    freq2.sort((a,b)=>a-b);

    return freq1.every((count,i)=> count === freq2[i]);
    
};