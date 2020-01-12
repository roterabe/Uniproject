function smallnav() {
    var x = document.getElementById("topnavigation");
    if (x.className === "topnav") {
        x.className += " responsive";
    } else {
        x.className = "topnav";
    }
}