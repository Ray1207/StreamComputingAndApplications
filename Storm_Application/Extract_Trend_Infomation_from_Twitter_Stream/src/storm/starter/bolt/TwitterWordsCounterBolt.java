package storm.starter.bolt;

import java.util.HashMap;
import java.util.Map;

import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class TwitterWordsCounterBolt extends BaseBasicBolt {
	Map<String, Integer> counts = new HashMap<String, Integer>();

	@Override
	public void execute(Tuple tuple, BasicOutputCollector collector) {
		String word = tuple.getString(0);
		Integer count = counts.get(word);
		if (count == null)
			count = 0;
		count++;
		counts.put(word, count);
		System.out.println("counts=" + counts);
		collector.emit(new Values(word, count));
	}
	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("word", "count"));
	}
}
