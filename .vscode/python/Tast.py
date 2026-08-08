from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler, ContextTypes
import gspread
from google.oauth2.service_account import Credentials

BOT_TOKEN = "8832353057:AAGvizKZsnYGDV3x3fXz2I5Mt21W-9qQPos"

# Google Sheets setup
SCOPES = ["https://www.googleapis.com/auth/spreadsheets.readonly"]

creds = Credentials.from_service_account_file(
    "credentials.json",
    scopes=SCOPES
)

client = gspread.authorize(creds)

# Replace with your Google Sheet name
sheet = client.open("TelegramBotCommands").sheet1


def get_command_text(command):
    records = sheet.get_all_records()

    for row in records:
        if row["Command"] == command:
            return f"{row['Title']}\n\n{row['Description']}"

    return "Command not found."


async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(
        "Welcome!\n\n"
        "/q1 - Developer\n"
        "/q2 - Software Architect\n"
        "/q3 - Tester (QA Engineer)\n"
        "/q4 - UX Designer\n"
        "/q5 - Business Analyst\n"
        "/q6 - Network Engineer\n"
        "/q7 - System Administrator\n"
        "/q8 - Database Administrator (DBA)\n"
        "/q9 - Cybersecurity Specialist\n"
        "/q10 - Project Manager"
    )


async def q1(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q1"))

async def q2(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q2"))

async def q3(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q3"))

async def q4(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q4"))

async def q5(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q5"))

async def q6(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q6"))

async def q7(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q7"))

async def q8(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q8"))

async def q9(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q9"))

async def q10(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(get_command_text("q10"))


def main():
    app = ApplicationBuilder().token(BOT_TOKEN).build()

    app.add_handler(CommandHandler("start", start))

    app.add_handler(CommandHandler("q1", q1))
    app.add_handler(CommandHandler("q2", q2))
    app.add_handler(CommandHandler("q3", q3))
    app.add_handler(CommandHandler("q4", q4))
    app.add_handler(CommandHandler("q5", q5))
    app.add_handler(CommandHandler("q6", q6))
    app.add_handler(CommandHandler("q7", q7))
    app.add_handler(CommandHandler("q8", q8))
    app.add_handler(CommandHandler("q9", q9))
    app.add_handler(CommandHandler("q10", q10))

    print("Bot is running...")
    app.run_polling()


if __name__ == "__main__":
    main()