function check(){
    let src = document.getElementById('inputText');
    let compareTo = document.getElementById('wordToCompare');
    let answer = document.getElementById("result");
    answer.innerHTML = src.value.indexOf(compareTo.value);
}
