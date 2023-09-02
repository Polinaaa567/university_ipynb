import asyncio
import aiohttp


async def get_ip(service):
    async with aiohttp.ClientSession() as session:
        async with session.get(service) as response:
            if response.status == 200:
                return await response.text(), service


async def main():
    services = ['https://api.ipify.org', 'http://ip-api.com']
    tasks = [get_ip(service) for service in services]
    done, pending = await asyncio.wait(tasks, return_when=asyncio.FIRST_COMPLETED)
    for task in done:
        result = task.result()
        if result:
            ip, service = result
            print(f"Your IP address is {ip} (from {service})")
            break


if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main())
