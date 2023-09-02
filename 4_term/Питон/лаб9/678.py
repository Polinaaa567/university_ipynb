import discord
import requests
import json

intents = discord.Intents.default()
intents.members = True
intents.message_content = True
client = discord.Client(intents=intents)

# Yandex Weather API key
api_key = '10410733-f10c-46a0-b1b2-d7ea273d38a0'

# Default location
location = 'Kemerovo'

# Help command
help_message = '''Tекущая погода и прогноз на несколько дней. 
Команды:
!help_bot - помощь
!place <место> - изменить место прогноза
!current - получить текущую погоду
!forecast <дней> - получить прогноз на указанное количество дней'''


def get_weather_data(location):
    url = f'https://api.weather.yandex.ru/v2/forecast'
    headers = {'X-Yandex-API-Key': api_key}
    response = requests.get(url, headers=headers)
    data = json.loads(response.text)
    return data


# Function to format weather data
def format_weather_data(data):
    fact = data['fact']
    temp = fact['temp']
    pressure = fact['pressure_mm']
    humidity = fact['humidity']
    wind_speed = fact['wind_speed']
    wind_dir = fact['wind_dir']
    return f'Температура: {temp}°C\n' \
           f'Давление: {pressure} мм рт. ст.\n' \
           f'Влажность: {humidity}%\n' \
           f'Ветер: {wind_speed} м/с, {wind_dir}'


def get_forecast_data(location, days):
    url = f'https://api.weather.yandex.ru/v1/forecast?&lang=en_US&location={location}&limit={days}' \
          f'&hours=false&extra=false'
    headers = {'X-Yandex-API-Key': api_key}
    response = requests.get(url, headers=headers)
    data = json.loads(response.text)
    forecast = ''
    for day in data['forecasts']:
        date = day['date']
        parts = day['parts']
        day_temp = parts['day']['temp_avg']
        day_prec = parts['day']['prec_mm']
        night_temp = parts['night']['temp_avg']
        night_prec = parts['night']['prec_mm']
        forecast += f'{date}: Днем {day_temp}°C, ' \
                    f'{day_prec} мм осадков. Ночью {night_temp}°C, {night_prec} мм осадков.\n'
    return forecast


# Discord events
@client.event
async def on_message(message):
    global location
    if message.author == client.user:
        return
    if message.content.startswith('!help_bot'):
        await message.channel.send(help_message)
    elif message.content.startswith('!place'):
        location = message.content.split(' ')[1]
        await message.channel.send(f'Место прогноза изменено на {location}')
    elif message.content.startswith('!current'):
        data = get_weather_data(location)
        weather = format_weather_data(data)
        await message.channel.send(f'Погода в {location}:\n{weather}')
    elif message.content.startswith('!forecast'):
        days = int(message.content.split(' ')[1])
        if days > 7:
            await message.channel.send('Прогноз доступен только на 7 дней')
        else:
            forecast = get_forecast_data(location, days)
            await message.channel.send(f'Прогноз в {location} на {days} дней:\n{forecast}')


# Discord login
client.run('MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI')
