package Main.repository;


import Main.dto.QuestionDto;
import Main.entity.Question;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface QuestionRepository extends JpaRepository<Question,Integer> {

//    List<Question> getQuestionsByDifficultyLevel(String difficultyLevel);
    List<Question> getAllQuestionsByTopic(String topic);

    @Query(value = "SELECT * FROM question q WHERE q.topic =:topic ORDER BY RANDOM() LIMIT :noOfQuestions",nativeQuery = true)
    List<Question> getQuestionsByTopic(String topic, Integer noOfQuestions);

}
