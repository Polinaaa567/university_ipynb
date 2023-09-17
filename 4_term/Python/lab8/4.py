import requests

response = requests.get(
    "http://geocode-maps.yandex.ru/1.x/?apikey=7a0332fa-0401-4a46-ac3c-da05786df316&geocode=Барнаул&format=json")
json_response = response.json()
toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Барнаул: " + toponym_region)

response = requests.get(
    "http://geocode-maps.yandex.ru/1.x/?apikey=7a0332fa-0401-4a46-ac3c-da05786df316&geocode=Мелеуз&format=json")
json_response = response.json()
toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Мелеуз: " + toponym_region)

response = requests.get(
    "http://geocode-maps.yandex.ru/1.x/?apikey=7a0332fa-0401-4a46-ac3c-da05786df316&geocode=Йошкар-Ола&format=json")
json_response = response.json()
toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
toponym_region = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["Components"][2]["name"]
print("Йошкар-Ола: " + toponym_region)
