import discord
from discord.ext import commands

config = {
    'token': 'MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI',
    'yandex_api': '10410733-f10c-46a0-b1b2-d7ea273d38a0'
}


intents = discord.Intents.default()
intents.members = True
intents.message_content = True

bot = commands.Bot(command_prefix='#!', intents=intents)


@bot.command(name='place')
async def place(ctx, country):
    await ctx.send("Place changed to " + country)


@bot.command(name='forecast')
async def forecast(ctx, days):
    await ctx.send("")


@bot.command(name='current')
async def forecast(ctx):
    pass


bot.run(config['token'])
