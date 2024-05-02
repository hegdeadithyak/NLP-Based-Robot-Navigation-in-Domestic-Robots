from flask import Flask, render_template,request
import subprocess

app = Flask(__name__)

@app.route('/')
def hello_world():
    return render_template('base.html')

@app.route('/input')
def input_page():
    return render_template('input.html')


@app.route('/run_script', methods=['POST'])
def run_script():
    input_value = request.form.get('input')
    command = ["python3", "main.py", input_value]
    process = subprocess.run(command, capture_output=True, text=True)
    return process.stdout
if __name__ == '__main__':
    app.run()
