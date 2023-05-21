import discord
import requests
import json
import aiohttp

config = {
    'token': 'MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI'
}


class HWBot(discord.Client):
    def random_dog(self):
        url1 = "https://dog.ceo/api/breeds/image/random"
        res = requests.get(url1)
        data = res.json()
        if 'message' in data:
            return data['message']
        return None

    def random_cat(self):
        url2 = "https://api.thecatapi.com/v1/images/search"
        res2 = requests.get(url2)
        data2 = res2.json()
        if 'url' in data2:
            return data2['url']
        return None

    async def on_ready(self):
        print(f'{self.user} Привет! Я подключился и готов показать котика или собачку')

    async def on_message(self, message):
        random_dog_png = self.random_dog()
        random_cat_png = self.random_cat()
        print(random_cat_png)
        print(random_dog_png)

        if message.author == self.user:
            return
        if "собака" in message.content.lower():
            embed = discord.Embed(title="рандомная собака!", color=discord.Color.purple())
            embed.set_image(url=random_dog_png)
            await message.channel.send(embed=embed)

        elif "кот" in message.content.lower():
            embed = discord.Embed(title="рандомный кот!", color=discord.Color.purple())
            embed.set_image(url=random_cat_png)
            await message.channel.send(embed=embed)
            # with open('cat.jpg', 'rb') as f:
            # embed = discord.Embed(title="Doggo!", color=discord.Color.purple())
            # embed.set_image(url=catjson['url'])
            # await message.send(embed=embed)
            # picture = discord.File(f)
            # await message.channel.send(file=picture)


intents = discord.Intents.default()
intents.members = True
intents.message_content = True
client = HWBot(intents=intents)
client.run(config['token'])
