async function loadNames() {

    const response = await fetch('/api/names');

    const names = await response.json();

    console.log(names);

    let html = "";

    for(let i = 0; i < names.length; i++) {

        html += `<li>${names[i].name}</li>`;

    }

    document.getElementById("lista").innerHTML = html;
}

loadNames();
