from time import sleep
import discord
from discord.ext import commands

config = {
    'token': 'MTEwOTc2MjQxMTI5ODI5NTg0OQ.Gbi8L_.DCURActB9AIRWIp_S_LCBmyZ5Zf6Z9QhBRUsMI'
}

intents = discord.Intents.default()
intents.members = True
intents.message_content = True

bot = commands.Bot(command_prefix='#!', intents=intents)


@bot.command(name='timer')
async def timer(ctx, seconds):
    sleep(int(seconds))
    await ctx.send("время X наступило!")


bot.run(config['token'])
