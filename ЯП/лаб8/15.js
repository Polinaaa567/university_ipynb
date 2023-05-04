function greet(lang, color) {
    switch(lang) {
        case 'en':
            document.write("<span style='color:" + color + " '>Hello!</span>");
            break;
        case 'ru':
            document.write("<span style='color:" + color + " '>Здравствуйте!</span>");
            break;
        case 'fr':
            document.write("<span style='color:" + color + " '>Bonjour!</span>");
            break;
        case 'de':
            document.write("<span style='color:" + color + " '>Guten Tag!</span>");
            break;
        default:
            document.write('Error: unknown language');
            break;
    }
}

let n = String(prompt());
let c = String(prompt());

greet(n, c);