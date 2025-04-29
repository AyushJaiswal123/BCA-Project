API_KEY='04a1512071bb45f0bdb102908243008';
async function showWeather(){
    let city='New Delhi'
    const response=await fetch(`http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${city}`)
    const data=await response.json();
    console.log('Weather data is:',data)
    let newpara=document.createElement('p')
    newpara.textContent=`${data?.current?.wind_mph}`
    document.body.appendChild(newpara)
}
showWeather();