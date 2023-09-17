import asyncio
from asyncio import create_task


async def soak(name, soakTime):
    await asyncio.sleep(soakTime / 1000)
    print(f"2 Soaking of the {name} is finished")


async def sprout(name, sproutTime):
    await asyncio.sleep(sproutTime / 1000)
    print(f"4 Shelter of the {name} is removed")


async def root(name, rootTime):
    await asyncio.sleep(rootTime / 1000)
    print(f"6 The {name} has taken root")


async def top_dressing(name):
    await asyncio.sleep(3 / 1000)
    print(f"7 Fertilizers for the {name} have been introduced")


async def treatment(name):
    await asyncio.sleep(5 / 1000)
    print(f"8 The {name} is treated from pests")


async def sowing(*plants):
    for plant in plants:
        name, soakTime, sproutTime, rootTime = plant

        print(f"0 Beginning of sowing the {name} plant")
        print(f"1 Soaking of the {name} started")
        task1 = create_task(soak(name, soakTime))
        task1
        print(f"3 Shelter of the {name} is supplied")
        task2 = create_task(sprout(name, sproutTime))
        task2
        print(f"5 The {name} has been transplanted")
        task3 = create_task(root(name, rootTime))
        task3
        print(f"7 Application of fertilizers for {name}")
        task4 = create_task(top_dressing(name))
        task4
        print(f"8 Treatment of {name} from pests")
        task5 = create_task(treatment(name))
        task5
        print(f"9 The seedlings of the {name} are ready")


data = [("carrot", 7, 18, 2), ("cabbage", 2, 6, 10), ("onion", 5, 12, 7)]
asyncio.run(sowing(*data))

# import asyncio
#
#
# async def sowing(*plants):
#     for plant in plants:
#         name, soakTime, sproutTime, rootTime = plant
#
#         print(f"0 Beginning of sowing the {name} plant")
#         print(f"1 Soaking of the {name} started")
#         await asyncio.sleep(soakTime / 1000)
#         print(f"2 Soaking of the {name} is finished")
#         print(f"3 Shelter of the {name} is supplied")
#         await asyncio.sleep(sproutTime / 1000)
#         print(f"4 Shelter of the {name} is removed")
#         print(f"5 The {name} has been transplanted")
#         await asyncio.sleep(rootTime / 1000)
#         print(f"6 The {name} has taken root")
#         print(f"7 Application of fertilizers for {name}")
#         await asyncio.sleep(3)
#         print(f"7 Fertilizers for the {name} have been introduced")
#         print(f"8 Treatment of {name} from pests")
#         await asyncio.sleep(5)
#         print(f"8 The {name} is treated from pests")
#         print(f"9 The seedlings of the {name} are ready")
#
#
# data = [("carrot", 7, 18, 2), ("cabbage", 2, 6, 10), ("onion", 5, 12, 7)]
# asyncio.run(sowing(*data))
