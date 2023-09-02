import requests

response = requests.get(
    "http://geocode-maps.yandex.ru/1.x/?apikey=7a0332fa-0401-4a46-ac3c-da05786df316&geocode=Москва,+Петровка,+38&format=json")
json_response = response.json()
toponym = json_response["response"]["GeoObjectCollection"]["featureMember"][0]["GeoObject"]
toponym_address = toponym["metaDataProperty"]["GeocoderMetaData"]["text"]
toponym_postal_code = toponym["metaDataProperty"]["GeocoderMetaData"]["Address"]["postal_code"]
print(toponym_address + " имеет почтовый индекс " + toponym_postal_code)
