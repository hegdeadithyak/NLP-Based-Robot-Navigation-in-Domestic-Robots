# NLP-Based-Robot-Navigation-in-Domestic-Robots

This repository combines ROS (Robot Operating System) with Natural Language Processing (NLP) algorithms such as LSTM, BERT, and SVM for classification tasks. The system is designed to enable robot navigation based on voice commands in domestic environments.

## Authors

- [Vikas P](https://github.com/Vikas-106)
- [Adithya Hegde Kota](https://github.com/hegdeadithyak)

# Overview
The integration of ROS and NLP technologies facilitates seamless communication and decision-making for domestic robots, particularly in scenarios involving serving food in a restaurant setting. The key components and functionalities of this repository are outlined below:

1. ROS (Robot Operating System)
ROS provides a flexible framework for robot software development, offering functionalities such as hardware abstraction, device control, communication between processes, and package management. It serves as the backbone for coordinating the various modules and tasks within the robotic system.

2. NLP Algorithms
   ### a. LSTM (Long Short-Term Memory)
   LSTM is a type of recurrent neural network (RNN) architecture designed to capture long-term dependencies in sequential data. In this context, LSTM models are utilized for understanding and
   interpreting natural language inputs, enabling the robot to comprehend commands and instructions from users.

    ### b. BERT (Bidirectional Encoder Representations from Transformers)
    BERT is a transformer-based machine learning model that excels in various NLP tasks, including text classification and language understanding. Leveraging BERT allows for enhanced semantic         understanding and context awareness in processing user queries and commands.

    ### c. SVM (Support Vector Machine)
    SVM is a supervised learning algorithm commonly used for classification tasks. Within this framework, SVM models are employed for classifying and categorizing relevant information extracted
       from user utterances, aiding in decision-making processes such as table selection for food service.

4. Integration with Vosk
    - Vosk is a state-of-the-art speech recognition library that enables accurate transcription of speech input. The system is designed to handle noise and variations in speech patterns, ensuring robust communication between users and the robot.

5. Table Selection for Food Service
    - The core functionality of the system revolves around determining the appropriate table for serving food based on user commands. By processing and analyzing input from Vosk and employing NLP algorithms, the system intelligently identifies the intended table and coordinates robot navigation to the designated location.

# Usage
To utilize the functionalities provided by this repository, follow the instructions provided in the respective folders. Detailed guidance on setting up the environment, running the demo, and integrating additional features may be found within the documentation.


![Screenshot from 2024-04-22 17-50-25](https://github.com/hegdeadithyak/ServeSpeak-The-Voice-Powered-Table-Attendant/assets/116452077/bb032d23-3ddd-4f35-a8a6-2af70f6efb5c)


<table>
    <thead>
        <tr>
            <th>Commands</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Go to Table 1</td>
            <td>Instructs to go to table 1</td>
        </tr>
        <tr>
            <td>Go to Table 2</td>
            <td>Instructs to go to table 2</td>
        </tr>
        <tr>
            <td>Go to Table 3</td>
            <td>Instructs to go to table 3</td>
        </tr>
        <tr>
            <td>Go to Table 4</td>
            <td>Instructs to go to table 4</td>
        </tr>
        <tr>
            <td>Anything Else</td>
            <td>Repeat Again?</td>
        </tr>
    </tbody>
</table>

