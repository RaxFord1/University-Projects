function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}
function DeleteShaking(){
    document.getElementById("rolls").classList.remove('shaking');
}
function AddClick(){
    fight_button.addEventListener("click", fight, false);
}
function addPlayerScore(){
    var el = document.getElementById("player_score");
    el.classList.add('increasing');
    el.innerHTML = parseInt(el.innerText)+1;
}
function addComputerScore(){
    var el = document.getElementById("computer_score");
    el.classList.add('increasing');
    el.innerHTML = parseInt(el.innerText)+1;
}
function animatePlayerWin(){
    let p1=document.getElementById("lasthit");
    p1.style.display = "block";
}
function animateComputerWin(){
    let p1=document.getElementById("hit");
    p1.style.display = "block";
}
function hideWin(){
    document.getElementById("hit").style.display="none";
    document.getElementById("lasthit").style.display="none";
}
function checkWinner(){
    let p1=document.getElementById("player_score");
    let p2=document.getElementById("computer_score");

    let firstValue = parseInt(p1.innerText);
    let secondValue = parseInt(p2.innerText);

    if (firstValue==3){
        animatePlayerWin();
        p1.innerText = "0";
        p2.innerText = "0";
    } else if (secondValue==3){
        animateComputerWin();
        p1.innerText = "0";
        p2.innerText = "0";
    }
    
}
function fight() {
    //reset

    document.getElementById("rolls").classList.remove('shaking');
    document.getElementById("player_score").classList.remove('increasing');
    document.getElementById("computer_score").classList.remove('increasing');

    var p1 = document.getElementById("first_player_value");
    var p2 = document.getElementById("second_player_value");

    document.getElementById("rolls").classList.add('shaking');
    fight_button.removeEventListener("click", fight);

    let rand_first = getRandomInt(10);
    let rand_second = getRandomInt(10);

    p1.innerHTML=rand_first;
    p2.innerHTML=rand_second;
    
    
    if (rand_first == rand_second) {
        
    } else if (rand_first > rand_second){
        setTimeout(addPlayerScore, 900);
    } else {
        setTimeout(addComputerScore, 900);
    }
    setTimeout(DeleteShaking, 1000);
    setTimeout(AddClick, 1000);

    setTimeout(checkWinner, 1000);
}

var fight_button = document.getElementById("fight_button");
fight_button.addEventListener("click", fight, false);
document.getElementById("rolls").classList.remove('shaking');
function promptName() {
    let value = prompt("Введіть ваше ім'я");
    while (value == ""){
        value = prompt("Ви не ввели ім'я. Спробуйте ще раз!");
    }
    document.getElementById("first_player_name").innerText = value;
};

document.addEventListener("DOMContentLoaded", promptName);

