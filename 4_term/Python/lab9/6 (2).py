from random import randint
from telegram.ext import Application, Updater, CommandHandler, filters, MessageHandler, CallbackContext
from telegram import ReplyKeyboardMarkup, ReplyKeyboardRemove

API_TOKEN = '6259887409:AAF8lqyviZQWKrekzCMgcqoW6mdg8grJy2M'

reply_keyboard = [
    ['/dice', '/timer']
]

dice_keyboard = [
    ["кинуть 1 шестигранный кубик", "кинуть 2 шестигранных кубика одновременно"],
    ["кинуть 20-гранный кубик", "вернуться назад"]
]

timer_keyboard = [
    ["30 секунд", "1 минута"],
    ["5 минут", "вернуться назад"]
]

close_keyboard = [
    ["/close"]
]

markup = ReplyKeyboardMarkup(reply_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_dice = ReplyKeyboardMarkup(dice_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_timer = ReplyKeyboardMarkup(timer_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_close = ReplyKeyboardMarkup(close_keyboard, one_time_keyboard=False, resize_keyboard=True)


async def start(update, context):
    await update.message.reply_text("start", reply_markup=markup)


async def dice(update, context):
    await update.message.reply_text("dice", reply_markup=markup_dice)


async def timer(update, context):
    await update.message.reply_text("timer", reply_markup=markup_timer)


def roll_cube(faces, count):
    nums = [randint(1, int(faces)) for _ in range(count)]
    return nums


def remove_job_if_exists(name, context):
    """Удаляем задачу по имени.
    Возвращаем True если задача была успешно удалена."""
    current_jobs = context.job_queue.get_jobs_by_name(name)
    if not current_jobs:
        return False
    for job in current_jobs:
        job.schedule_removal()
    return True


async def set_timer(update, context, time):
    chat_id = update.effective_message.chat_id
    due = int(time)
    job_removed = remove_job_if_exists(str(chat_id), context)
    context.job_queue.run_once(task, due, chat_id=chat_id, name=str(chat_id), data=due)

    text = f'Вернусь через {due} с.!'
    await update.effective_message.reply_text(text)
    #
    # chat_id = update.effective_message.chat_id
    #
    #
    # if 'job' in context.chat_data:
    #     old_job = context.chat_data['job']
    #     old_job.schedule_removal()
    # new_job = context.job_queue.run_once(task, due, chat_id=chat_id, name=str(chat_id), data=due)
    # context.chat_data['job'] = new_job
    # await update.message.reply_text(f'Засек {due} секунд')


async def task(context):
    job = context.job
    await context.bot.send_message(job.context, text='Указанное время истекло')


async def unset_timer(update, context):
    if 'job' not in context.chat_data:
        await update.message.reply_text('Нет активного таймера', reply_markup=markup_timer)
        return
    job = context.chat_data['job']
    job.schedule_removal()
    del context.chat_data['job']
    await update.message.reply_text('Сбрасываю таймер', reply_markup=markup_timer)


async def ans(update, context):
    if update.message.text == "кинуть 1 шестигранный кубик":
        num = roll_cube(6, 1)
        await update.message.reply_text(*num)
    elif update.message.text == "кинуть 2 шестигранных кубика одновременно":
        nums = list(map(str, roll_cube(6, 2)))
        str_nums = str(nums[0]) + ", " + str(nums[1])
        await update.message.reply_text(str_nums)
    elif update.message.text == "кинуть 20-гранный кубик":
        num = roll_cube(20, 1)
        await update.message.reply_text(*num)
    elif update.message.text == "30 секунд":
        await set_timer(update, context, 30)
    elif update.message.text == "1 минута":
        await set_timer(update, context, 60)
    elif update.message.text == "5 минут":
        await set_timer(update, context, 300)
    elif update.message.text == "вернуться назад":
        await update.message.reply_text("вернуться назад", reply_markup=markup)


application = Application.builder().token(API_TOKEN).build()

application.add_handler(CommandHandler("start", start))
application.add_handler(CommandHandler("dice", dice))
application.add_handler(CommandHandler("timer", timer))
application.add_handler(CommandHandler("close", unset_timer))
application.add_handler(MessageHandler(filters.TEXT, ans))

application.run_polling()
