

// async function showWeather(){
//     let city='ambala'
//     const response=await fetch(`http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${city}`)
//     const data=await response.json();
//     console.log('Weather data is:',data)
//     let newpara=document.createElement('p')
//     newpara.textContent=`${data?.current?.temp_c.toFixed(2)}C`
//     document.body.appendChild(newpara)
// }
// showWeather();

const userTab=document.querySelector('[data-userWeather]')
const searchTab=document.querySelector('[data-searchWeather]')
const userContainer=document.querySelector('.weather-container')
const grantaccessContainer=document.querySelector('.grant-location-container')
const searchForm=document.querySelector('[data-searchform]')
const loadingScreen=document.querySelector('.loading-container')
const userInfoContainer=document.querySelector('.user-info-container')


let oldTab=userTab;
const API_KEY="04a1512071bb45f0bdb102908243008";
oldTab.classList.add('current-tab');
getfromSessionStorage();

function switchTab(newTab){
if(newTab!=oldTab){
    oldTab.classList.remove('current-tab');
    oldTab=newTab;
    oldTab.classList.add('current-tab');

    if(!searchForm.classList.contains("active")){
            userInfoContainer.classList.remove("active")
            grantaccessContainer.classList.remove("active")
            searchForm.classList.add("active")
    }
    else{
        searchTab.classList.remove("active")
        userInfoContainer.classList.remove("active")
        getfromSessionStorage();
    }
}
}


userTab.addEventListener('click',()=>{
    switchTab(userTab);
})

searchTab.addEventListener('click',()=>{
    switchTab(searchTab);
})

function getfromSessionStorage(){
    const localCoordinates=sessionStorage.getItem("user-coordinates");
    if(!localCoordinates){
        grantaccessContainer.classList.add("active")
    }
    else{
        const coordinates=JSON.parse(localCoordinates)
        fetchUserweatherInfo(coordinates)
    }

}
async function fetchUserweatherInfo(coordinates){
    const {lat,lon}=coordinates;
    grantaccessContainer.classList.remove("active")
    loadingScreen.classList.add("active")
    try{
        const response=await fetch(`http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${lat},${lon}&aqi=no`)
        const data=await response.json();
        loadingScreen.classList.remove("active")
        userInfoContainer.classList.add("active")
        renderWeatherInfo(data);

    }

    catch(err){
        loadingScreen.classList.remove("active")
    }
}
function renderWeatherInfo(weatherInfo){
    const cityName=document.querySelector('[data-cityName]')
    const countryIcon=document.querySelector('[data-countryIcon]')
    const desc=document.querySelector('[data-weatherDesc]')
    const weatherIcon=document.querySelector('[data-weatherIcon]')
    const temp=document.querySelector('[data-temp]')
    const windSpeed=document.querySelector('[data-windspeed]')
    const humidity=document.querySelector('[data-humidity]')
    const cloudiness=document.querySelector('[data-cloudiness]')
    

    cityName.innerText=weatherInfo?.location?.name
     console.log('city name',cityName);                      //MAY NOT WORK HERE*******
   
    const countryName=weatherInfo?.location?.country;
    console.log('country name',countryName)       //RISKY CODE
    const countryCodes = {
        "India": "IN",
        "United States": "US",
        "Canada": "CA",
        "Australia": "AU",
        "United Kingdom": "GB",
        "Germany": "DE",
        "France": "FR",
        "Italy": "IT",
        "Spain": "ES",
        "Mexico": "MX",
        "Brazil": "BR",
        "Japan": "JP",
        "China": "CN",
        "Russia": "RU",
        "South Africa": "ZA",
        "Argentina": "AR",
        "New Zealand": "NZ",
        "Sweden": "SE",
        "Norway": "NO",
        "Finland": "FI",
        "Denmark": "DK",
        "Netherlands": "NL",
        "Belgium": "BE",
        "Switzerland": "CH",
        "Austria": "AT",
        "Poland": "PL",
        "Portugal": "PT",
        "Greece": "GR",
        "Turkey": "TR",
        "Saudi Arabia": "SA",
        "United Arab Emirates": "AE",
        "Israel": "IL",
        "Egypt": "EG",
        "Indonesia": "ID",
        "Malaysia": "MY",
        "Singapore": "SG",
        "South Korea": "KR",
        "Thailand": "TH",
        "Vietnam": "VN",
        "Philippines": "PH",
        "Pakistan": "PK",
        "Bangladesh": "BD",
        "Nigeria": "NG",
        "Kenya": "KE",
        "Morocco": "MA",
        "Colombia": "CO",
        "Chile": "CL",
        "Peru": "PE",
        "Venezuela": "VE",
        "Ukraine": "UA",
        "Kazakhstan": "KZ",
        "Hungary": "HU",
        "Czech Republic": "CZ",
        "Romania": "RO"
    };
    const countryCode = countryCodes[countryName];
    console.log('Country Code:', countryCode);
    countryIcon.src=`https://flagcdn.com/144x108/${countryCode.toLowerCase()}.png`;//Risky here
    desc.innerText=weatherInfo?.current?.condition?.text;
    weatherIcon.src=
    // "//cdn.weatherapi.com/weather/64x64/day/143.png", or
    weatherInfo?.current?.condition?.icon;
    temp.innerText=weatherInfo?.current?.temp_c;
    windSpeed.innerText=weatherInfo?.current?.wind_mph;
    humidity.innerText=weatherInfo?.current?.humidity;
    cloudiness.innerText=weatherInfo?.current?.cloud
    

}
function getLocation(){
    if(navigator.geolocation){
        navigator.geolocation.getCurrentPosition(showPosition)
    }
    else{
        alert('No Geo-Location Support Available!!')
    }
}
function showPosition(position){
    const userCoordinates={
        lat:position.coords.latitude,
        lon:position.coords.longitude,
    }
    sessionStorage.setItem("user-coordinates",JSON.stringify(userCoordinates));
    fetchUserweatherInfo(userCoordinates);


}
const grantAccessButton=document.querySelector('[data-grantAccess]');
grantAccessButton.addEventListener('click',getLocation);

const searchInput=document.querySelector('[data-searchInput]')
searchForm.addEventListener('submit',(e)=>{
    e.preventDefault();
    let cityName=searchInput.ariaValueMax;
    if(cityName==""){
        return;
    }
    else{
        fetchSearchWeatherInfo(cityName);
    }

})

async function fetchSearchWeatherInfo(city){
    loadingScreen.classList.add("active");
    userInfoContainer.classList.remove("active");
    grantaccessContainer.classList.remove("active");

    try{
        const response=await fetch(`http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${city}`);
        const data=await response.json();
        loadingScreen.classList.remove("active")
        userInfoContainer.classList.remove("active")
        renderWeatherInfo(data);
    }
    catch(err){
        
    }
}