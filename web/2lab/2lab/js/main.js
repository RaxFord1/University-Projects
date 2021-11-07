document.forms.registrationForm.onsubmit = function() {
    var pas1 = this.pass.value;
    var pas2 = this.confirm_pass.value;
    if (pas1 != pas2) {
      alert("Паролі мають співпадати!");
    }
  }
  