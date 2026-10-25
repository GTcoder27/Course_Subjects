package Main.controller;

import Main.dto.QuestionDto;
import Main.service.QuestionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("question")
public class QuestionController {
    @Autowired
    QuestionService questionService;

    @PostMapping("add")
    public String addQuestion(@RequestBody List<QuestionDto> questions){
        return questionService.addQuestion(questions);
    }

    @GetMapping("allquestions")
    public List<QuestionDto> getAllQuestions(){
        return questionService.getAllQuestions();
    }

//    @GetMapping("difficulty_level/{difficultyLevel}")
//    public ResponseEntity<List<QuestionDto>> getQuestionsByDifficultyLevel(@PathVariable String difficultyLevel) {
//        return questionService.getQuestionsByDifficultyLevel(difficultyLevel);
//    }

    @GetMapping("topic/{topic}")
    public List<QuestionDto> getAllQuestionsByTopic(@PathVariable String topic){
        return questionService.getAllQuestionsByTopic(topic);
    }

    @GetMapping("topic/{topic}/{noOfQuestions}")
    public List<QuestionDto> getQuestionsByTopic(@PathVariable String topic,@PathVariable Integer noOfQuestions){
        return questionService.getQuestionsByTopic(topic,noOfQuestions);
    }






}
