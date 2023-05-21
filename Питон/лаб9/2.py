import os
import time
import asyncio
from datetime import datetime

COEFF = 1


async def dish(el):
    print(f"{el[0]} started the 1 task.")
    await asyncio.sleep(el[1] / 100)
    print(f"{el[0]} moved on to the defense of the 1 task.")
    await asyncio.sleep(el[2] / 100)
    print(f"{el[0]} completed the 1 task.")
    print(f"{el[0]} is resting.")
    await asyncio.sleep(5 / 100)
    print(f"{el[0]} started the 2 task.")
    await asyncio.sleep(el[3] / 100)
    print(f"{el[0]} moved on to the defense of the 2 task.")
    await asyncio.sleep(el[4] / 100)
    print(f"{el[0]} completed the 2 task.")


async def interviews(*data):
    tasks = [
        asyncio.create_task(dish(i)) for i in data
    ]
    await asyncio.gather(*tasks)


if __name__ == '__main__':
    t0 = time.time()  # запоминаем время начала работы
    if os.name == 'nt':
        asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())
