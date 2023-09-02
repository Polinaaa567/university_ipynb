import discord
import requests

config = {
    'token': 'MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI'
}


class HWBot(discord.Client):
    async def on_ready(self):
        print(f'{self.user} Привет! Я подключился и готов показать котика или собачку')

    async def on_message(self, message):
        if message.author == self.user:
            return
        if "собака" in message.content.lower():
            response = requests.get("https://dog.ceo/api/breeds/image/random").json()
            dog_url = response['message']
            embed = discord.Embed(title="рандомная собака!", color=discord.Color.purple())
            embed.set_image(url=dog_url)
            await message.channel.send(embed=embed)

        elif "кот" in message.content.lower():
            response = requests.get("https://api.thecatapi.com/v1/images/search").json()
            cat_url = response[0]['url']
            random_cat_png = discord.Embed(title="рандомный кот!", color=discord.Color.purple())
            random_cat_png.set_image(url=cat_url)
            await message.channel.send(embed=random_cat_png)


intents = discord.Intents.default()
intents.members = True
intents.message_content = True
client = HWBot(intents=intents)
client.run(config['token'])
