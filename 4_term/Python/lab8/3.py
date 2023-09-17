import requests

response = requests.get(
    "http://geocode-maps.yandex.ru/1.x/?apikey=7a0332fa-0401-4a46-ac3c-da05786df316&geocode=Москва,+Красная+площадь,+1&format=json")
json_response = response.json()
toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
toponym_coodrinates = toponym["Point"]["pos"]
print(toponym_address, "имеет координаты:", toponym_coodrinates)
