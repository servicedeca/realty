<div class="container fin">
  <div class="col-xs-8 col-xs-offset-1 doc-block">
    <?php if(isset($documents)):?>
      <?php foreach($documents as $document):?>
        <div class="col-xs-12 zero-padding doc-item">
          <div class="col-xs-1 doc-icon zero-padding">
            <a href="#">
              <?php print $image?>
            </a>
          </div>
          <div class="col-xs-11 doc-title">
            <p>
              <?php print $document['title']?>
            </p>
          </div>
          <div class="col-xs-11 col-xs-ofset-1 doc-download">
            <?php print $document['link_download']?>
            /
            <?php print $document['link_view']?>
          </div>
        </div>
      <?php endforeach;?>
    <?php endif?>
  </div>
</div>