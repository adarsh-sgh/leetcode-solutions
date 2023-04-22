/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const words = s.split(' ').filter(w=>w.length);
    words.reverse();
    return words.join(' ');


};