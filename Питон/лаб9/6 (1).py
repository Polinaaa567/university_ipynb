from telegram.ext import Application, CommandHandler, MessageHandler, filters
from telegram import ReplyKeyboardMarkup

API_TOKEN = '6259887409:AAF8lqyviZQWKrekzCMgcqoW6mdg8grJy2M'

enter_keyboard = [
    ['Перейти в зал №1']
]

room1_keyboard = [
    ['Перейти в зал №2', 'Выход']
]

room2_keyboard = [
    ['Перейти в зал №3']
]

room3_keyboard = [
    ['Перейти в зал №1', 'Перейти в зал №4']
]

room4_keyboard = [
    ['Перейти в зал №1']
]

markup_enter = ReplyKeyboardMarkup(enter_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_room1 = ReplyKeyboardMarkup(room1_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_room2 = ReplyKeyboardMarkup(room2_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_room3 = ReplyKeyboardMarkup(room3_keyboard, one_time_keyboard=False, resize_keyboard=True)
markup_room4 = ReplyKeyboardMarkup(room4_keyboard, one_time_keyboard=False, resize_keyboard=True)


async def start(update, context):
    if update.message.text == '/start':
        await update.message.reply_text(
            "Добро пожаловать!\n"
            "Пожалуйста, сдайте верхнюю одежду в гардероб\n",
            reply_markup=markup_enter)
        await update.message.reply_text(
            "1 - Айвазовский")

    elif update.message.text == 'Перейти в зал №1':
        await update.message.reply_text(
            "Вы зашли в 1 зал\n"
            "В данном зале представлены картины великого живописца Ивана Константиновича Айвазовского",
            reply_markup=markup_room1)
        await update.message.reply_text(
            "2 - Клод Моне")
        await update.message.reply_text(
            "Выход - выход")

    elif update.message.text == 'Перейти в зал №2':
        await update.message.reply_text(
            "Вы зашли вo 2 зал\n"
            "В данном зале представлены картины Клода Моне",
            reply_markup=markup_room2)
        await update.message.reply_text(
            "3 - Сальвадор Дали")

    elif update.message.text == 'Перейти в зал №3':
        await update.message.reply_text(
            "Вы зашли в 3 зал\n"
            "В данном зале представлены картины испанского живописца Сальвадора Дали",
            reply_markup=markup_room3)
        await update.message.reply_text(
            "4 - Леонардо да Винчи")
        await update.message.reply_text(
            "1 - Айвазовский")

    elif update.message.text == 'Перейти в зал №4':
        await update.message.reply_text(
            "Вы зашли в 4 зал\n"
            "В данном зале представлены картины итальянского художника Леонардо да Винчи",
            reply_markup=markup_room4)
        await update.message.reply_text(
            "1 - Айвазовский")

    elif update.message.text == 'Выход':
        await update.message.reply_text(
            "Всего доброго, не забудьте забрать верхнюю одежду в гардеробе")


def main():
    application = Application.builder().token(API_TOKEN).build()
    application.add_handler(CommandHandler("start", start))
    application.add_handler(MessageHandler(filters.TEXT, start))
    application.run_polling()


if __name__ == '__main__':
    main()
