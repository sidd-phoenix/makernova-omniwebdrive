var theme_change = document.getElementById('thm_change');
const drishti_logo = document.getElementsByClassName('logo2')[0]
var curr_theme = 'dark';


theme_change.addEventListener('click', () => {

    if (curr_theme == 'dark') {
        document.body.style.setProperty('--bg-color', 'white');
        document.body.style.setProperty('--font-color', 'rgba(0, 0, 0, 0.892)');
        document.body.style.setProperty('--bg-comp', 'rgba(87, 87, 87, 0.708)');
        drishti_logo.setAttribute('src', 'drishti_logo.png');
        document.getElementById('thm_change').style.border = '2px solid black';
        curr_theme = 'light';
    }
    else {
        document.body.style.setProperty('--bg-color', 'rgba(0, 0, 0, 0.892)');
        document.body.style.setProperty('--font-color', 'white');
        document.body.style.setProperty('--bg-comp', 'rgba(87, 87, 87, 0.708)');
        drishti_logo.setAttribute('src', 'drishti_logo_white.png');
        document.getElementById('thm_change').style.border = '2px solid white';
        curr_theme = 'dark';
    }
})

window.addEventListener('load', () => {
    var curr_window = window.location.href


    if (curr_window == 'http://127.0.0.1:5500/base.html')
        //highlight home
        console.log('base');
    else if (curr_window == 'http://127.0.0.1:5500/control.html')
        //highlight control
        console.log('control');
})