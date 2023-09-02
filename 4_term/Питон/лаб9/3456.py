import discord
import requests
import json
from datetime import datetime, timedelta
from discord.ext import commands

intents = discord.Intents.default()
intents.members = True
intents.message_content = True

bot = commands.Bot(command_prefix='!', intents=intents)

TOKEN = 'MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI'


def get_weather(city: str, days: int) -> str:
    """
    Функция для получения данных о погоде в городе на указанное количество дней
    :param city: Город, для которого нужно получить данные о погоде
    :param days: Количество дней для прогноза погоды
    :return: Строка с информацией о погоде
    """
    url = "https://api.weather.yandex.ru/v2/forecast?"
    params = {
        "city": city,
        "limit": days
    }

    headers = {
        "X-Yandex-API-Key": "10410733-f10c-46a0-b1b2-d7ea273d38a0"  # заменить на свой ключ API
    }

    response = requests.get(url, headers=headers, params=params)

    if response.status_code != 200:
        return "Не удалось получить данные о погоде"

    data = json.loads(response.text)

    # Данные о текущей погоде
    current = data["fact"]
    temp = current["temp"]
    pressure = current["pressure_mm"]
    humidity = current["humidity"]
    wind_direction = current["wind_dir"]
    wind_speed = current["wind_speed"]

    # Данные о прогнозе погоды на указанное количество дней
    forecast = data["forecasts"]
    forecast_info = "\n".join(
        [f"{day['date']}: днем {day['parts']['day']['temp_avg']}°, {day['parts']['day']['condition']}" for day in
         forecast])

    # Составление строки с информацией о погоде
    weather_info = f"Текущая погода в {city}: {temp}°C, давление {pressure} мм рт.ст., влажность {humidity}%, ветер {wind_direction} {wind_speed} м/с\n\nПрогноз погоды на {days} дней:\n{forecast_info}"

    return weather_info


@bot.event
async def on_ready():
    print(f'{bot.user.name} подключен к Discord!')


@bot.command(name='help_bot')
async def help_bot(ctx):
    """
    Команда help_bot для вывода информации о функционале бота
    """
    await ctx.send("Список команд:\n - place [город] - "
                   "выбрать город для получения прогноза погоды\n"
                   " - current - получить текущую погоду\n"
                   " - forecast [число] - получить прогноз погоды на указанное количество дней")


@bot.command(name='place')
async def place(ctx, city: str):
    """
    Команда place для выбора города
    """
    global selected_city
    selected_city = city
    await ctx.send(f"Выбран город {selected_city}")


@bot.command(name='current')
async def current(ctx):
    """
    Команда current для получения текущей погоды
    """
    if "selected_city" in globals():
        weather_info = get_weather(selected_city, 1)
        await ctx.send(weather_info)
    else:
        await ctx.send("Город не выбран. Используйте команду !place [город] для выбора города")


@bot.command(name='forecast')
async def forecast(ctx, days: int):
    """
    Команда forecast для получения прогноза погоды на указанное количество дней
    """
    if "selected_city" in globals():
        weather_info = get_weather(selected_city, days)
        await ctx.send(weather_info)
    else:
        await ctx.send("Город не выбран. Используйте команду !place [город] для выбора города")


bot.run(TOKEN)
